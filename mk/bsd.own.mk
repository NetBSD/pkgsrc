#	$NetBSD: bsd.own.mk,v 1.14 1999/03/15 12:49:01 mrg Exp $
# From:  NetBSD: bsd.own.mk,v 1.120 1999/02/24 14:42:36 drochner Exp

.if !defined(_PKGSRC_BSD_OWN_MK_)
_PKGSRC_BSD_OWN_MK_=1

.if defined(MAKECONF) && exists(${MAKECONF})
.include "${MAKECONF}"
.elif exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif

# set the default local base.
LOCALBASE?=	/usr/pkg

# set the default operating system
OS?=		NetBSD

.if ${OS} == "SunOS.5"
BSDDIR=${LOCALBASE}/bsd
.if exists(${BSDDIR}/lib/libbsdcompat.so.1.0)
LDADD+=-L${BSDDIR}/lib -R${BSDDIR}/lib -lbsdcompat -lposix4 -lsocket -lnsl
.else
LDADD+=-L${BSDDIR}/lib -R${BSDDIR}/lib -lposix4 -lsocket -lnsl
.endif
BINDIR=${BSDDIR}/bin
.endif

# Defining `SKEY' causes support for S/key authentication to be compiled in.
SKEY=		yes
# Defining `KERBEROS' causes support for Kerberos authentication to be
# compiled in.
#KERBEROS=	yes
# Defining 'KERBEROS5' causes support for Kerberos5 authentication to be
# compiled in.
#KERBEROS5=	yes

# where the system object and source trees are kept; can be configurable
# by the user in case they want them in ~/foosrc and ~/fooobj, for example
BSDSRCDIR?=	/usr/src
BSDOBJDIR?=	/usr/obj

.if ${OS} == "SunOS.5"
WHEEL?=		sys
_OWN_PREFIX?=	${BSDDIR}
.else
WHEEL?=		wheel
_OWN_PREFIX?=	/usr
.endif

BINGRP?=	${WHEEL}
BINOWN?=	root
BINMODE?=	555
NONBINMODE?=	444

# Define MANZ to have the man pages compressed (gzip)
#MANZ=		1

.if ${OS} == "SunOS.5"
MANDIR?=	${BSDDIR}/man
.else
MANDIR?=	/usr/share/man
.endif
MANGRP?=	${WHEEL}
MANOWN?=	root
MANMODE?=	${NONBINMODE}
MANINSTALL?=	maninstall catinstall

INFODIR?=	/usr/share/info
INFOGRP?=	wheel
INFOOWN?=	root
INFOMODE?=	${NONBINMODE}

LIBDIR?=	${_OWN_PREFIX}/lib
LINTLIBDIR?=	${_OWN_PREFIX}/libdata/lint
LIBGRP?=	${BINGRP}
LIBOWN?=	${BINOWN}
LIBMODE?=	${NONBINMODE}

DOCDIR?=        ${_OWN_PREFIX}/share/doc
DOCGRP?=	${WHEEL}
DOCOWN?=	root
DOCMODE?=       ${NONBINMODE}

NLSDIR?=	${_OWN_PREFIX}/share/nls
NLSGRP?=	${WHEEL}
NLSOWN?=	root
NLSMODE?=	${NONBINMODE}

KMODDIR?=	${_OWN_PREFIX}/lkm
KMODGRP?=	${WHEEL}
KMODOWN?=	root
KMODMODE?=	${NONBINMODE}

TMACDIR?=	${_OWN_PREFIX}/share/tmac

COPY?=		-c
.if defined(UPDATE)
PRESERVE?=	-p
.else
PRESERVE?=
.endif
RENAME?=
STRIPFLAG?=	-s

# Define SYS_INCLUDE to indicate whether you want symbolic links to the system
# source (``symlinks''), or a separate copy (``copies''); (latter useful
# in environments where it's not possible to keep /sys publicly readable)
#SYS_INCLUDE= 	symlinks

# XXX The next two are temporary until the transition to UVM is complete.


.if ${OS} == "SunOS.5"
OBJECT_FMT?=	ELF
SHLIB_TYPE?=    ${OBJECT_FMT}
.else
# The NETBSD_CURRENT checks are to make sure that UVM is defined only
# if the user is running a NetBSD-current, as well as the right platform
# It's also used to find out about SHLIB_TYPE.
# I'm told that 1.3C was the first version with UVM	XXX - agc
NETBSD_CURRENT!= /usr/bin/uname -r | /usr/bin/sed -e 's|^1\.3[C-Z]$$|yes|'

.if !defined(UVM)
.if (${NETBSD_CURRENT} == "yes")
# Systems on which UVM is the standard VM system.
.if ${MACHINE} != "pica"
UVM?=		yes
.endif

# Systems that use UVM's new pmap interface.
.if ${MACHINE} == "alpha" || \
    ${MACHINE} == "i386" || \
    ${MACHINE} == "pc532" || \
    ${MACHINE} == "vax"
PMAP_NEW?=	yes
.endif

.endif # NetBSD-current

.endif # !UVM

# The sparc64 port is incomplete.
.if ${MACHINE_ARCH} == "sparc64"
NOPROFILE=1
NOPIC=1
NOLINT=1
.endif

# The PowerPC port is incomplete.
.if ${MACHINE_ARCH} == "powerpc"
NOPROFILE=
.endif

# Data-driven table using make variables to control how 
# toolchain-dependent targets and shared libraries are built
# for different platforms and object formats.
# OBJECT_FMT:		currently either "ELF" or "a.out".
# SHLIB_TYPE:		"ELF" or "a.out" or "" to force static libraries.
#
.if (${NETBSD_CURRENT} == "yes")
.if ${MACHINE_ARCH} == "alpha" || \
    ${MACHINE_ARCH} == "mipsel" || ${MACHINE_ARCH} == "mipseb" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "sparc64"
OBJECT_FMT?=ELF
.else
OBJECT_FMT?=a.out
.endif
SHLIB_TYPE?=	${OBJECT_FMT}

.else  # ! NetBSD-current, backward compatibility stuff

.if (${MACHINE_ARCH} == "alpha") || \
    (${MACHINE_ARCH} == "mips") || \
    (${MACHINE_ARCH} == "powerpc")
OBJECT_FMT?=ELF
.else
OBJECT_FMT?=a.out
.endif

.if (${MACHINE_ARCH} == "vax") || \
    (${MACHINE_ARCH} == "powerpc")
SHLIB_TYPE?=    "" 
.else   
SHLIB_TYPE?=    ${OBJECT_FMT}
.endif  # vax || powerpc
.endif	# !NetBSD-current
.endif	# NetBSD


# GNU sources and packages sometimes see architecture names differently.
# This table maps an architecture name to its GNU counterpart.
# Use as so:  ${GNU_ARCH.${TARGET_ARCH}} or ${MACHINE_GNU_ARCH}
GNU_ARCH.alpha=alpha
GNU_ARCH.arm32=arm
GNU_ARCH.i386=i386
GNU_ARCH.m68k=m68k
GNU_ARCH.mipseb=mipseb
GNU_ARCH.mipsel=mipsel
GNU_ARCH.ns32k=ns32k
GNU_ARCH.powerpc=powerpc
GNU_ARCH.sparc=sparc
GNU_ARCH.sparc64=sparc
GNU_ARCH.vax=vax
.if ${MACHINE_ARCH} == "mips"
.INIT:
	@echo Must set MACHINE_ARCH to one of mipseb or mipsel
	@false
.endif

.if ${MACHINE_ARCH} == "sparc64"
MACHINE_GNU_ARCH=${MACHINE_ARCH}
.else
MACHINE_GNU_ARCH=${GNU_ARCH.${MACHINE_ARCH}}
.endif

TARGETS+=	all clean cleandir depend distclean includes install lint obj \
		regress tags
.PHONY:		all clean cleandir depend distclean includes install lint obj \
		regress tags beforedepend afterdepend beforeinstall \
		afterinstall realinstall

# set NEED_OWN_INSTALL_TARGET, if it's not already set, to yes
# this is used by bsd.pkg.mk to stop "install" being defined
NEED_OWN_INSTALL_TARGET?=	yes

.if ${NEED_OWN_INSTALL_TARGET} == "yes"
.if !target(install)
install:	.NOTMAIN beforeinstall subdir-install realinstall afterinstall
beforeinstall:	.NOTMAIN
subdir-install:	.NOTMAIN beforeinstall
realinstall:	.NOTMAIN beforeinstall
afterinstall:	.NOTMAIN subdir-install realinstall
.endif #! install target
.endif #! NEED_OWN_INSTALL_TARGET

# Define MKxxx variables (which are either yes or no) for users
# to set in /etc/mk.conf and override on the make commandline.
# These should be tested with `== "no"' or `!= "no"'.
# The NOxxx variables should only be used by Makefiles.
#

MKCATPAGES?=yes

.if defined(NODOC)
MKDOC=no
#.elif !defined(MKDOC)
#MKDOC=yes
.else
MKDOC?=yes
.endif

MKINFO?=yes

.if defined(NOLINKLIB)
MKLINKLIB=no
.else
MKLINKLIB?=yes
.endif
.if ${MKLINKLIB} == "no"
MKPICINSTALL=no
MKPROFILE=no
.endif

.if defined(NOLINT)
MKLINT=no
.else
MKLINT?=yes
.endif

.if defined(NOMAN)
MKMAN=no
.else
MKMAN?=yes
.endif
.if ${MKMAN} == "no"
MKCATPAGES=no
.endif

.if defined(NONLS)
MKNLS=no
.else
MKNLS?=yes
.endif

.if defined(NOOBJ)
MKOBJ=no
.else
MKOBJ?=yes
.endif

.if defined(NOPIC)
MKPIC=no
.else
MKPIC?=yes
.endif

.if defined(NOPICINSTALL)
MKPICINSTALL=no
.else
MKPICINSTALL?=yes
.endif

.if defined(NOPROFILE)
MKPROFILE=no
.else
MKPROFILE?=yes
.endif

.if defined(NOSHARE)
MKSHARE=no
.else
MKSHARE?=yes
.endif
.if ${MKSHARE} == "no"
MKCATPAGES=no
MKDOC=no
MKINFO=no
MKMAN=no
MKNLS=no
.endif

.endif		# _PKGSRC_BSD_OWN_MK_
