# $NetBSD: Makefile,v 1.44 2003/11/23 08:35:05 jlam Exp $

DISTNAME=	xpkgwedge-1.8
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools devel x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Allows X11 pkgs to be built and used outside of $${X11BASE}

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	# defined
NO_BUILDLINK=	# defined
NO_CHECKSUM=	# defined

USE_X11=		YES
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
INSTALLATION_DIRS=	bin lib/X11/config

# FONT_PROGS are symlinked from ${X11BASE}/bin to ${PREFIX}/bin to allow
# ${PREFIX}/bin/${prog} to always work.
#
FONT_PROGS=		bdftopcf fstobdf mkfontdir

FILES_SUBST+=		FONT_PROGS=${FONT_PROGS:Q}
FILES_SUBST+=		MAKE=${MAKE_PROGRAM:Q}

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/pkgxmkmf.in > ${WRKDIR}/pkgxmkmf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/config
	${INSTALL_DATA} ${FILESDIR}/xpkgwedge.def ${PREFIX}/lib/X11/config
	${INSTALL_SCRIPT} ${WRKSRC}/pkgxmkmf ${PREFIX}/bin/pkgxmkmf

.include "../../mk/bsd.pkg.mk"
