# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:33 rillig Exp $
#

DISTNAME=	mailgraph-1.12
CATEGORIES=	mail
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/mailgraph/pub/ \
		http://people.ee.ethz.ch/~dws/software/mailgraph/pub/old/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://people.ee.ethz.ch/~dws/software/mailgraph/
COMMENT=	RRDtool frontend for mail statistics

DEPENDS+=	rrdtool-1*:../../databases/rrdtool
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail

USE_PKGINSTALL=	yes
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

DBDIR?=		${VARBASE}/db/${PKGBASE}

MG_SCRIPTS=	mailgraph.cgi mailgraph.pl

REPLACE_PERL=	${MG_SCRIPTS}

CGIDIR=		libexec/cgi-bin
DOCDIR=		share/doc/${PKGBASE}

OWN_DIRS+=	${PREFIX}/${DOCDIR}
RCD_SCRIPTS=	mailgraph

PLIST_SUBST+=	CGIDIR=${CGIDIR:Q}
PLIST_SUBST+=	DOCDIR=${DOCDIR:Q}

SUBST_CLASSES+=		defs

SUBST_STAGE.defs=	pre-build
SUBST_FILES.defs=	${MG_SCRIPTS}
# Database
SUBST_SED.defs+=	-e 's,/var/log\([^/]\),${DBDIR}\1,g'
SUBST_SED.defs+=	-e 's,/var/log$$,${DBDIR},g'
# Logfile
SUBST_SED.defs+=	-e 's,/var/log/syslog,${VARBASE}/log/maillog,g'
#
SUBST_MESSAGE.defs=	"Fixing defaults"

INSTALLATION_DIRS=	${CGIDIR} sbin
do-build:

do-configure:

do-install:
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/mailgraph.cgi ${PREFIX}/${CGIDIR}/mailgraph.cgi
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/mailgraph.pl ${PREFIX}/sbin/mailgraph
.for i in CHANGES COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
