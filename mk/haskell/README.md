<!-- $NetBSD: README.md,v 1.1 2022/02/11 05:24:06 pho Exp $ -->

# Packaging guide for Haskell packages

## `PKGNAME`

Packages that only make sense to be implemented in Haskell should have a
prefix `hs-` to avoid conflicts with non-Haskell packages. Libraries fall
into this category. Packages that install both a library and executables
also fall into this, if their libraries are the main body and their
executables are supplemental. `mk/haskell.mk` prepends the prefix by
default.

Packages that happen to be implemented in Haskell but could have been done
otherwise should not have the prefix `hs-`. Applications fall into this
category. Packages that install libraries too also fall into this, if their
executables are the main body. You can remove the prefix by declaring this
in your `Makefile`:

```
PKGNAME=	${DISTNAME}
```


## Tools

Some packages have build-time dependencies on external tools, which are
typically Haskell source preprocessors. At the time of this writing the
following tools are available via the variable `USE_TOOLS`:

* pkg-config (which isn't specific to Haskell of course)
* alex
* cpphs
* happy

`mk/haskell.mk` generates dummy scripts for these tools by default, which
unconditionally aborts the build with an error message. This is to prevent
packages from silently depending on the tools.


## `buildlink3.mk`

Packages with the prefix `hs-` should have `buildlink3.mk` like this:

```
BUILDLINK_TREE+=	hs-distributive

.if !defined(HS_DISTRIBUTIVE_BUILDLINK3_MK)
HS_DISTRIBUTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-distributive+=	hs-distributive>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-distributive+=	hs-distributive>=0.6.2.1nb2
BUILDLINK_PKGSRCDIR.hs-distributive?=	../../math/hs-distributive

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_DISTRIBUTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-distributive
```

This is a `buildlink3.mk` for a package `math/hs-distributive` version
`0.6.2.1`. The important part of this is that `buildlink3.mk` should have
both `BUILDLINK_API_DEPENDS.*` and `BUILDLINK_ABI_DEPENDS.*`. The latter
should be set to the exact version of the package because a Haskell
package, once compiled, can provide absolutely zero ABI compatibility with
any other versions of the same package.

`BUILDLINK_API_DEPENDS.*` should have up to three version components but
not more. This is because every Haskell package is supposed to follow [the
versioning policy described here](https://pvp.haskell.org/). That is, for a
version `A.B.C.D` the first two components `A.B` describes a major API
version, whose change indicates a breaking one. The third component `C`
desibes a minor API version whose change indicates a non-breaking API
change. The fourth component `D` describes a patch version which introduces
no API changes. It therefore doesn't make sense to include `D` in our
`BUILDLINK_API_DEPENDS.*`.
