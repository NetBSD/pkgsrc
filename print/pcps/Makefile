# $NetBSD: Makefile,v 1.8 2003/07/17 22:52:36 grant Exp $
#

DISTNAME=	pcps840
PKGNAME=	pcps-8.40
WRKSRC=		${WRKDIR}
CATEGORIES=	print textproc
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/pcps/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.swreg.org/soft_shop/695/shopscr3.shtml
COMMENT=	converts text files to PostScript(tm)

MAKEFILE=	makefile
ALL_TARGET=
MAKE_ENV+=	"CC=${CC} ${CFLAGS} -DUNIX"
NO_CONFIGURE=	yes

LICENSE=        shareware
RESTRICTED=	This is shareware for your evaluation and subsequent payment
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

post-patch:
	${SED} "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/pcps.1 > ${WRKDIR}/pcps.1

do-install:
	@${INSTALL_PROGRAM}  ${WRKSRC}/pcps ${PREFIX}/bin/pcps
	@${INSTALL_MAN}      ${WRKDIR}/pcps.1 ${PREFIX}/man/man1
	@${INSTALL_DATA}     ${FILESDIR}/pcps.cfg ${PREFIX}/bin/pcps.cfg
	@${INSTALL_DATA_DIR} ${WRKSRC}/license.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/license.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/register.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/pcps.man ${PREFIX}/share/doc/pcps

.include "../../mk/bsd.pkg.mk"
