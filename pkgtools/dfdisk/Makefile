# $NetBSD: Makefile,v 1.2 2003/07/17 22:52:13 grant Exp $
#

DISTNAME=	dfdisk-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Fetch distfiles from multiple locations

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_PKGINSTALL=	yes

EGDIR=		${PREFIX}/share/examples/dfdisk
CONF_FILES=	${EGDIR}/dfdisk.conf ${PKG_SYSCONFDIR}/dfdisk.conf

FILES_SUBST+=	PKGVERSION="${PKGVERSION}"

.include "../../mk/bsd.prefs.mk"

.if exists(${ZOULARISBASE}/bin/ftp)
FILES_SUBST+=	FTP="${ZOULARISBASE}/bin/ftp -p"
.else
FILES_SUBST+=	FTP="/usr/bin/ftp -p"
.endif

do-build:
.for f in dfdisk.sh dfdisk.1 dfdisk.conf
	@${ECHO} "Generating $f..."
	@${SED} ${FILES_SUBST_SED} < ${FILESDIR}/$f > ${WRKDIR}/$f
.endfor
.undef f

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dfdisk.sh ${PREFIX}/bin/dfdisk
	${INSTALL_DATA} ${WRKDIR}/dfdisk.1 ${PREFIX}/man/man1/dfdisk.1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/dfdisk.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
