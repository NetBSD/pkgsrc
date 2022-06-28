# $NetBSD: Makefile,v 1.30 2022/06/28 11:34:22 wiz Exp $

DISTNAME=	mailgraph-1.14
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	https://mailgraph.schweikert.ch/pub/
MASTER_SITES+=	https://mailgraph.schweikert.ch/pub/old/

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://mailgraph.schweikert.ch/
COMMENT=	RRDtool frontend for mail statistics
LICENSE=	gnu-gpl-v2

DEPENDS+=	rrdtool>=1:../../databases/rrdtool
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail

USE_TOOLS+=	perl:run
NO_BUILD=	yes

REPLACE_PERL+=	mailgraph.cgi mailgraph.pl

BUILD_DEFS+=	VARBASE

OWN_DIRS+=	${VARBASE}/db/mailgraph

RCD_SCRIPTS=	mailgraph

SUBST_CLASSES+=		var
SUBST_STAGE.var=	pre-configure
SUBST_MESSAGE.var=	Fixing hardcoded /var.
SUBST_FILES.var=	mailgraph.cgi mailgraph.pl
SUBST_VARS.var=		VARBASE

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.cgi \
		${DESTDIR}${PREFIX}/libexec/cgi-bin/mailgraph.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.pl \
		${DESTDIR}${PREFIX}/sbin/mailgraph
	${INSTALL_DATA} ${WRKSRC}/mailgraph.css \
	  	${DESTDIR}${PREFIX}/share/mailgraph/mailgraph.css
	${INSTALL_DATA} ${WRKSRC}/CHANGES \
		${DESTDIR}${PREFIX}/share/doc/mailgraph/CHANGES
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/mailgraph/COPYING
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/mailgraph/README

.include "../../mk/bsd.pkg.mk"
