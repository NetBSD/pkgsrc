# $NetBSD: Makefile,v 1.22 2012/10/08 13:45:43 asau Exp $
#

DISTNAME=	pcps840
PKGNAME=	pcps-8.40
PKGREVISION=	1
CATEGORIES=	print textproc
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/pcps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swreg.org/soft_shop/695/shopscr3.shtml
COMMENT=	Converts text files to PostScript(tm)
LICENSE=	pcps-license

RESTRICTED=	This is shareware for your evaluation and subsequent payment
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
BUILD_TARGET=
MAKE_ENV+=	"CC=${CC} ${CFLAGS} -DUNIX"
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pcps share/examples/pcps

CONF_FILES+=	${PREFIX}/share/examples/pcps/pcps.cfg ${PREFIX}/bin/pcps.cfg

post-patch:
	${SED} "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/pcps.1 > ${WRKDIR}/pcps.1

do-install:
	@${INSTALL_PROGRAM}  ${WRKSRC}/pcps ${DESTDIR}${PREFIX}/bin/pcps
	@${INSTALL_MAN}      ${WRKDIR}/pcps.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@${INSTALL_DATA}     ${WRKSRC}/license.doc ${DESTDIR}${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/register.doc ${DESTDIR}${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/pcps.man ${DESTDIR}${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${FILESDIR}/pcps.cfg ${DESTDIR}${PREFIX}/share/examples/pcps/pcps.cfg

.include "../../mk/bsd.pkg.mk"
