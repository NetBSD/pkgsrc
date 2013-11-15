# $NetBSD: Makefile,v 1.19 2013/11/15 19:29:10 shattered Exp $
#

DISTNAME=	mailgraph-1.14
CATEGORIES=	mail
MASTER_SITES=	http://mailgraph.schweikert.ch/pub/	\
		http://mailgraph.schweikert.ch/pub/old

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mailgraph.schweikert.ch/
COMMENT=	RRDtool frontend for mail statistics

DEPENDS+=	rrdtool>=1:../../databases/rrdtool
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail

USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

DBDIR?=		${VARBASE}/db/${PKGBASE}

MG_SCRIPTS=	mailgraph.cgi mailgraph.pl

REPLACE_PERL+=	${MG_SCRIPTS}

RCD_SCRIPTS=	mailgraph

SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	pre-build
SUBST_FILES.defs=	${MG_SCRIPTS}
# Database
SUBST_SED.defs+=	-e 's,/var/log\([^/]\),${DBDIR}\1,g'
SUBST_SED.defs+=	-e 's,/var/log$$,${DBDIR},g'
# Logfile
SUBST_SED.defs+=	-e 's,/var/log/syslog,${VARBASE}/log/maillog,g'
#
SUBST_MESSAGE.defs=	Fixing defaults.

INSTALLATION_DIRS=	sbin

do-build:

do-configure:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.cgi \
		${DESTDIR}${PREFIX}/libexec/cgi-bin/mailgraph.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.pl \
		${DESTDIR}${PREFIX}/sbin/mailgraph
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mailgraph
.for i in CHANGES COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} \
		${DESTDIR}${PREFIX}/share/doc/mailgraph/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
