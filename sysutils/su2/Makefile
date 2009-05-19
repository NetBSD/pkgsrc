# $NetBSD: Makefile,v 1.13 2009/05/19 08:59:35 wiz Exp $
#

DISTNAME=		su2-1.3
CATEGORIES=		sysutils security
MASTER_SITES=		ftp://ftp.ccs.neu.edu/pub/sysadmin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.ccs.neu.edu/pub/sysadmin/
COMMENT=		Enhanced su, users su with own password + more
LICENSE=		su2-license

RESTRICTED=		may not be sold for profit
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_CONFIGURE=		yes

SUBST_CLASSES+=		preproc
SUBST_MESSAGE.preproc=	Correcting C preprocessor directives.
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
