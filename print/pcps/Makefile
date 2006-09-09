# $NetBSD: Makefile,v 1.17 2006/09/09 02:46:08 obache Exp $
#

DISTNAME=	pcps840
PKGNAME=	pcps-8.40
PKGREVISION=	1
CATEGORIES=	print textproc
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/pcps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swreg.org/soft_shop/695/shopscr3.shtml
COMMENT=	Converts text files to PostScript(tm)

WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
BUILD_TARGET=
MAKE_ENV+=	"CC=${CC} ${CFLAGS} -DUNIX"
NO_CONFIGURE=	yes

LICENSE=        pcps-license
RESTRICTED=	This is shareware for your evaluation and subsequent payment
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

INSTALLATION_DIRS=	bin man/man1

CONF_FILES+=	${PREFIX}/share/examples/pcps/pcps.cfg ${PREFIX}/bin/pcps.cfg

post-patch:
	${SED} "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/pcps.1 > ${WRKDIR}/pcps.1

do-install:
	@${INSTALL_PROGRAM}  ${WRKSRC}/pcps ${PREFIX}/bin/pcps
	@${INSTALL_MAN}      ${WRKDIR}/pcps.1 ${PREFIX}/man/man1
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/license.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/register.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/pcps.man ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pcps
	@${INSTALL_DATA}     ${FILESDIR}/pcps.cfg ${PREFIX}/share/examples/pcps/pcps.cfg

.include "../../mk/bsd.pkg.mk"
