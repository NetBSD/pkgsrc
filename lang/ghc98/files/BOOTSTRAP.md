<!-- $NetBSD: BOOTSTRAP.md,v 1.2 2024/05/05 16:16:21 pho Exp $ -->

# We need GHC to build GHC

GHC requires itself to build, and unfortunately the only way to get a
working GHC for a foreign target is to do a cross-compilation.

In order to build a bootkit for a new platform, you need to manually set up
a cross-building C compiler and binutils, libc, libterminfo, and libiconv
for the target. Then you can follow instructions in
https://gitlab.haskell.org/ghc/ghc/wikis/building/cross-compiling

Once you get a working GHC for the target platform, install it somewhere in
your PATH, run "bmake clean; bmake bootstrap" on the target platform and
you'll have a bootkit for the target. *But read a note below on the build
system.*


## The build system "Hadrian" is also written in Haskell

[Migrating from Make to Hadrian (for
packagers)](https://www.haskell.org/ghc/blog/20220805-make-to-hadrian.html)

GHC devs had used GNU Make to build GHC for decades, but its Makefiles had
grown unwieldy to the point where maintenance was virtually
impossible. They were in need of something more expressive than Make and
eventually developed their own build system named Hadrian, which is written
in Haskell. Unfortunately to us, this makes our lives harder for three
reasons:

1. Haskell libraries required to build Hadrian isn't bundled with GHC. We
   either need to use `misc/cabal-install` to fetch them (which isn't an
   option because we can't build cabal-install without GHC), or use a
   separate source tarball to bootstrap Hadrian.
2. The source tarball of Hadrian dependencies is specific to bootkit
   version. That is, if we are to use GHC 9.2.1 as our bootkit, we need a
   source tarball specific to GHC 9.2.1.
3. The required tarballs aren't distributed officially. We must roll them
   in our own hand. But in order to do it you need a working instance of
   `misc/cabal-install`.

So we must provide not only GHC bootkits but also Hadrian deps tarballs in
our LOCAL_PORTS.


### How to create `HADRIAN_BOOT_SOURCE` for your bootkit

The name of Hadrian deps tarball is defined as `${HADRIAN_BOOT_SOURCE}` in
`bootstrap.mk`. If you find one in our LOCAL_PORTS it means someone has
already created it and you don't need to do anything special. It is
platform-independent. It's only tied with a specific version of GHC. Just
do `bmake` and it will first bootstrap Hadrian and then use it to build the
entire package. If not, you have to create a tarball specific to your
bootkit version.

First, check if GHC has a so-called "build plan" in
`${WRKSRC}/hadrian/bootstrap`. If you find
`plan-bootstrap-${BOOT_VERSION}.json` for your bootkit version then you can
skip this step. If not, install `misc/cabal-install` and do:

```
% cd ${WRKSRC}/hadrian
% ../../../files/extract-vanilla-package-db ./packages.conf
(The next command fails with an error but you can safely ignore it.)
% cabal build --package-db=clear --package-db=./packages.conf --allow-newer
% cp dist-newstyle/cache/plan.json bootstrap/plan-${BOOT_VERSION}.json
% cd ./bootstrap
% cabal build --allow-newer
% cabal run -v0 --allow-newer hadrian-bootstrap-gen \
      -- plan-${BOOT_VERSION}.json | \
      tee plan-bootstrap-${BOOT_VERSION}.json
```

Now you have a build plan. Create a tarball like so:

```
% cd ${WRKSRC}/hadrian/bootstrap
% ./bootstrap.py --deps plan-bootstrap-${BOOT_VERSION}.json fetch \
      -o ghc-${BOOT_VERSION}-boot-hadrian-${PKGPATH:T}
```

Now you have `ghc-${BOOT_VERSION}-boot-hadrian-${PKGPATH:T}.tar.gz` that is
necessary to bootstrap Hadrian with your bootkit. Copy it to `${DISTDIR}`,
and if you're a pkgsrc developer place it in LOCAL_PORTS.


## HC files in ancient times, where have they gone?

GHC in fact has never supported bootstrapping only with a C compiler.
Prior to GHC 7, it had a thing called "HC source", which was a set of C
source files compiled from Haskell source, but it wasn't actually
cross-platform. It was because HC files were generated with many
assumptions about the platform, such as the layout of libc structs, the
size of `off_t` and `time_t`, byte-order, word size, etc.
