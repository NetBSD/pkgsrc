# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:45 agc Exp $
#

DISTNAME=	pcps840
PKGNAME=	pcps-8.40
CATEGORIES=	print textproc
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/pcps/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.swreg.org/soft_shop/695/shopscr3.shtml
COMMENT=	converts text files to PostScript(tm)

MAKEFILE=	makefile
ALL_TARGET=
MAKE_ENV+=	"CC=${CC} ${CFLAGS} -DUNIX"
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

LICENSE=        shareware
RESTRICTED=	This is shareware for your evaluation and subsequent payment
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

do-install:
	@${INSTALL_PROGRAM}  ${WRKSRC}/pcps ${PREFIX}/bin/pcps
	@${INSTALL_MAN}      ${FILESDIR}/pcps.1 ${PREFIX}/man/man1
	@${INSTALL_DATA}     ${FILESDIR}/pcps.cfg ${PREFIX}/bin/pcps.cfg
	@${INSTALL_DATA_DIR} ${WRKSRC}/license.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/license.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/register.doc ${PREFIX}/share/doc/pcps
	@${INSTALL_DATA}     ${WRKSRC}/pcps.man ${PREFIX}/share/doc/pcps

.include "../../mk/bsd.pkg.mk"
