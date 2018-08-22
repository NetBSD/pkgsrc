# $NetBSD: Makefile,v 1.26 2018/08/22 09:45:12 wiz Exp $
#

DISTNAME=	get_ds7_1.2.4
PKGNAME=	get_ds7-1.2.4
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/index-e.html
COMMENT=	Read pictures from a FUJIFILM DS-7(DS series) digital camera

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}/ds-7_1.2.4

PERL5_CONFIGURE=	no
NO_BUILD=		yes

DOCDIR=		${PREFIX}/share/doc/get_ds7

INSTALLATION_DIRS=	bin

post-patch:
	${SED}	-e "s,/usr/bin/perl,${PERL5}," \
		<${WRKSRC}/get_ds7 >${WRKSRC}/get_ds7.exe

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/ds7_lib.pm ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/get_ds7.exe ${DESTDIR}${PREFIX}/bin/get_ds7
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README.english ${DESTDIR}${DOCDIR}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
