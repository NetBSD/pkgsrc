# $NetBSD: Makefile,v 1.91 2023/11/17 17:40:47 abs Exp $

PKGNAME=	pkg_chk-2.0.12
CATEGORIES=	pkgtools

OWNER=		abs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Check installed package versions against pkgsrc
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_TOOLS+=	mktemp:run
USE_TOOLS+=	gzcat:run
USE_TOOLS+=	gzip:run
USE_TOOLS+=	bzcat:run
NO_BUILD=	yes
NO_CHECKSUM=	yes

CONFLICTS=	pkgchk-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Configuring sources.
SUBST_FILES.vars=	pkg_chk.sh pkg_chk.8
SUBST_VARS.vars=	AWK BZCAT GREP GZCAT GZIP_CMD ID MAKE MAKECONF MKTEMP \
			PKG_ADD PKG_ADMIN PKG_DELETE PKG_INFO PKG_SYSCONFDIR \
			SED SH SORT TSORT PREFIX PKG_DBDIR XARGS

REPLACE_SH+=		pkg_chk.sh

do-extract:
	cp ${FILESDIR}/pkg_chk.sh ${WRKSRC}
	cp ${FILESDIR}/pkg_chk.8 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_chk.sh ${DESTDIR}/${PREFIX}/sbin/pkg_chk
	${INSTALL_MAN} ${WRKSRC}/pkg_chk.8 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/pkg_chk.8

.include "../../mk/bsd.pkg.mk"
