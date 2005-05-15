# $NetBSD: Makefile,v 1.10 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	colorize_0.3.0
PKGNAME=	colorize-0.3.0
CATEGORIES=	misc
MASTER_SITES=	http://nrg.martos.bme.hu/release/colorize/download/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://nrg.martos.bme.hu/release/colorize/
COMMENT=	Log colorize perl script

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_BUILD=	yes
USE_PERL5=	yes

PKGSRC_USE_TOOLS+=	gunzip

post-patch:
	${SED}	-e "s,/usr/bin/perl,${LOCALBASE}/bin/perl,"		\
		-e "s,/etc/colorizerc,${PREFIX}/etc/colorizerc,"	\
		${WRKSRC}/colorize.pl > ${WRKSRC}/colorize.pl.done
	${MV} ${WRKSRC}/colorize.pl.done ${WRKSRC}/colorize.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colorize.pl ${PREFIX}/bin/colorize
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/colorize
	${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/share/examples/colorize
	${GUNZIP_CMD} ${WRKSRC}/colorize.pl.1.gz
	${INSTALL_MAN} ${WRKSRC}/colorize.pl.1 ${PREFIX}/man/man1/colorize.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/colorize
	cd ${WRKSRC} && ${INSTALL_DATA} README TIPS ${PREFIX}/share/doc/colorize
	${GUNZIP_CMD} ${WRKSRC}/examples/colorize-fifo.sh.gz
	${GUNZIP_CMD} ${WRKSRC}/examples/colorize-tail.sh.gz
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-fifo.sh		\
		${PREFIX}/share/examples/colorize
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-tail.sh		\
		${PREFIX}/share/examples/colorize
	${INSTALL_DATA} ${WRKSRC}/examples/Xlog.tar.gz ${PREFIX}/share/examples/colorize

.include "../../mk/bsd.pkg.mk"
