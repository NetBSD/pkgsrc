# $NetBSD: Makefile,v 1.13 2007/07/08 22:32:15 xtraeme Exp $
#

DISTNAME=	mailgraph-1.13
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://mailgraph.schweikert.ch/pub/

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
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/mailgraph.cgi ${PREFIX}/libexec/cgi-bin/mailgraph.cgi
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/mailgraph.pl ${PREFIX}/sbin/mailgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mailgraph
.for i in CHANGES COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/mailgraph/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
