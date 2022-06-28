# $NetBSD: Makefile,v 1.20 2022/06/28 11:31:48 wiz Exp $

DISTNAME=	libwhisker2-2.5
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=whisker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/whisker/
COMMENT=	Perl module geared specifically for HTTP testing
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_TOOLS+=	perl:run
REPLACE_PERL=	scripts/api_demo.pl scripts/crawl_demo.pl \
		scripts/simple_demo.pl scripts/form_demo1.pl \
		scripts/form_demo2.pl scripts/prox.pl

INSTALLATION_DIRS+=	libdata/${PKGBASE} share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/examples/${PKGBASE}

do-build:
	cd ${WRKSRC} && ${PERL5} Makefile.pl lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LW2.pm \
		${DESTDIR}${PREFIX}/libdata/${PKGBASE}

.for f in ${REPLACE_PERL}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
.endfor

.include "../../mk/bsd.pkg.mk"
