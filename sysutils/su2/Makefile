# $NetBSD: Makefile,v 1.8 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		su2-1.3
CATEGORIES=		sysutils security
MASTER_SITES=		ftp://ftp.ccs.neu.edu/pub/sysadmin/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		ftp://ftp.ccs.neu.edu/pub/sysadmin/
COMMENT=		Enhanced su, users su with own password + more

LICENSE=		no-profit
NO_CONFIGURE=		yes

SUBST_CLASSES+=		preproc
SUBST_MESSAGE.preproc=	"Correcting C preprocessor directives."
SUBST_STAGE.preproc=	post-patch
SUBST_FILES.preproc=	su2.c
SUBST_SED.preproc=	-e 's,^\(\# *else\).*,\1,' \
			-e 's,^\(\# *endif\).*,\1,'

LDLIBS=			-lcrypt

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LDLIBS+=		-lcompat
.endif

MAKE_ENV+=		LDLIBS=${LDLIBS:Q}

post-extract:
	${CHMOD} -R og+w ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
