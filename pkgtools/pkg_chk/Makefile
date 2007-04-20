# $NetBSD: Makefile,v 1.50 2007/04/20 09:25:36 tron Exp $

DISTNAME=	pkg_chk-1.85
PKGREVISION=	2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Check installed package versions against pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
USE_TOOLS+=	mktemp:run
NO_CHECKSUM=	YES

CONFLICTS=	pkgchk-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"

# Avoid changing any the actual value of MAKECONF
TMP_MAKECONF=${MAKECONF}
TMP_MAKECONF?=/etc/mk.conf

#XXX: how to get GZIP_CMD?!
do-build:
	${SED} -e 's#@AWK@#${AWK}#g' \
	  -e 's#@GREP@#${GREP}#g' \
	  -e 's#@GZIP_CMD@#gzip#g' \
	  -e 's#@MAKE@#${MAKE}#g' \
	  -e 's#@MAKECONF@#${TMP_MAKECONF}#g' \
	  -e 's#@PKG_ADD@#${PKG_ADD}#g' \
	  -e 's#@PKG_DELETE@#${PKG_DELETE}#g' \
	  -e 's#@PKG_INFO@#${PKG_INFO}#g' \
	  -e 's#@SED@#${SED}#g' \
	  -e 's#@SH@#${SH}#g' \
	  -e 's#@SORT@#${SORT}#g' \
	  -e 's#@TSORT@#${TSORT}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  -e 's#@PKG_DBDIR@#${PKG_DBDIR}#g' \
	  ${FILESDIR}/pkg_chk.sh >${WRKSRC}/pkg_chk.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_chk.sh ${PREFIX}/sbin/pkg_chk
	${INSTALL_MAN} ${FILESDIR}/pkg_chk.8 ${PREFIX}/${PKGMANDIR}/man8/pkg_chk.8

.include "../../mk/bsd.pkg.mk"
