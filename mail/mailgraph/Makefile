# $NetBSD: Makefile,v 1.3 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	mailgraph-1.10
CATEGORIES=	mail
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/mailgraph/pub/ \
		http://people.ee.ethz.ch/~dws/software/mailgraph/pub/old/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://people.ee.ethz.ch/~dws/software/mailgraph/
COMMENT=	RRDtool frontend for mail statistics

USE_PKGINSTALL=	yes
USE_PERL5=	yes

DEPENDS+=	rrdtool-1*:../../databases/rrdtool
DEPENDS+=	p5-File-Tail-[0-9]*:../../misc/p5-File-Tail

USE_LANGUAGES=	yes
USE_PERL5=	# defined

.include "../../mk/bsd.prefs.mk"

DBDIR?=		${VARBASE}/db/${PKGBASE}

MG_SCRIPTS=	mailgraph.cgi mailgraph.pl

REPLACE_PERL=	${MG_SCRIPTS}

CGIDIR=		libexec/cgi-bin
DOCDIR=		share/doc/${PKGBASE}

OWN_DIRS+=	${PREFIX}/${DOCDIR}
RCD_SCRIPTS=	mailgraph

PLIST_SUBST+=	CGIDIR="${CGIDIR}"
PLIST_SUBST+=	DOCDIR="${DOCDIR}"

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
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}/$i
.endfor

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
