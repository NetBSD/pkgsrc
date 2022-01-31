pkgsrc
======

[pkgsrc](https://pkgsrc.org) is a framework for building software for a
variety of UNIX-like systems.

It produces binary packages, which can be managed with tools such as
[pkgin](http://pkgin.net/). pkgsrc is highly configurable, supporting
building packages for an arbitrary installation prefix (the default is
`/usr/pkg`), allowing multiple branches to coexist on one machine, a
build options framework, and a compiler transformation framework, among
other advanced features. Unprivileged use and installation is also supported.

pkgsrc is the default package manager for [NetBSD](https://www.NetBSD.org/)
and [SmartOS](https://www.joyent.com/smartos).
It's also supported as a first-class option in [OmniOS CE](https://omniosce.org/)
and [Oasis Linux](https://github.com/oasislinux/oasis).


Bootstrapping
-------------

To use pkgsrc on operating systems other than NetBSD, you first need to
bootstrap:

	cd pkgsrc/bootstrap
	./bootstrap

Note that this is only for the most simple case, using pkgsrc's defaults.

Please consult `bootstrap/README` and `bootstrap/README.OS` for detailed
information about bootstrapping.

Building packages
-----------------

	cd pkgsrc/category/package-name
	$PREFIX/bin/bmake install

Where `$PREFIX` is where you've chosen to install packages
(typically `/usr/pkg`)

On NetBSD, `bmake` is simply the built-in `make` tool.

To build packages in bulk, tools such as `pkgtools/pbulk` and
`pkgtools/pkg_comp` can be used.

Community / Troubleshooting
---------------------------

- Join the community IRC channel [#pkgsrc @ libera.chat](https://web.libera.chat/#pkgsrc).
- Join the community Matrix room [#pkgsrc:nil.im](https://matrix.to/#/!YcdqKPizLfuTGHacZp:matrix.org)
- Subscribe to the [pkgsrc-users](https://www.NetBSD.org/mailinglists/#pkgsrc-users) mailing list
- Send bugs and patches [via web form](https://www.NetBSD.org/cgi-bin/sendpr.cgi?gndb=netbsd) (use the `pkg` category).

Latest sources
--------------

To fetch the main CVS repository:

	cvs -d anoncvs@anoncvs.NetBSD.org:/cvsroot checkout -P pkgsrc

To work in the Git mirror, which is updated every few hours from CVS:

	git clone https://github.com/NetBSD/pkgsrc.git

Additional links
----------------

- [pkgsrc guide](https://www.NetBSD.org/docs/pkgsrc/) - the authoritative document on pkgsrc, also available as `doc/pkgsrc.txt`
- [pkgsrc in the NetBSD Wiki](https://wiki.NetBSD.org/pkgsrc/) - miscellaneous articles and tutorials
- [pkgsrc.se](https://pkgsrc.se/) - a searchable web index of pkgsrc
- [pkgsrc-wip](https://pkgsrc.org/wip/) - a project to get more people actively involved with creating packages for pkgsrc
- [pkgsrc on Twitter](https://twitter.com/pkgsrc) - announcements to the world
- [pkgsrcCon](https://pkgsrc.org/pkgsrcCon) - we get together
- [BulkTracker](https://bulktracker.appspot.com/) - a web application that tracks pkgsrc bulk builds
