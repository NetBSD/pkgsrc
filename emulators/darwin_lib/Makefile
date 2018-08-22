# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:04 wiz Exp $

DISTNAME=	darwin_lib-6.6.2
PKGREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	# http://www.opendarwin.org/downloads/6.6.2/RPMS/ \
#		http://www.opendarwin.org/downloads/6.6.2/RPMS/${DARWIN_ARCH}/
DISTFILES=	org.opendarwin.Libsystem-6.6.2-4.fat.rpm \
		org.opendarwin.Libm-6.6.2-4.fat.rpm \
		org.opendarwin.cctools-6.6.2-4.fat.rpm \
		org.opendarwin.ncurses-6.6.2-4.fat.rpm \
		org.opendarwin.IOKitUser-6.6.2-4.fat.rpm \
		org.opendarwin.XFree86-6.6.2-4.${DARWIN_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Darwin compatibility libraries (including X11)

# The opendarwin.org domain is completely gone.  MASTER_SITES should
# probably point to ${MASTER_SITE_LOCAL} instead.  I also think the ppc
# XFree86 RPM is no longer available anywhere.
#
#HOMEPAGE=	http://www.opendarwin.org/

EMUL_PLATFORMS=		darwin-i386 darwin-powerpc
ONLY_FOR_PLATFORM=	NetBSD-1.6Z*-powerpc NetBSD-1.6Z*-i386		\
			NetBSD-[2-9]*-powerpc NetBSD-[2-9]*-i386

PKG_DESTDIR_SUPPORT=	destdir

DARWIN_PKG=		yes
DARWIN_ARCH=		${MACHINE_ARCH:C/powerpc/ppc/:C/x86_64/i386/}
WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STAGE=		do-install
RPMIGNOREPATH=		./Developer ./usr/X11R6/lib/X11/doc/html	\
			./usr/share/man ./usr/include ./usr/X11R6/man	\
			./usr/X11R6/include ./usr/local/include		\
			./usr/local/man

.include "../../mk/bsd.pkg.mk"
