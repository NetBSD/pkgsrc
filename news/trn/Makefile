# $NetBSD: Makefile,v 1.3 1999/08/18 09:08:10 agc Exp $
#

DISTNAME=		trn-3.6
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.wustl.edu/packages/news/readers/trn/

MAINTAINER=     	packages@netbsd.org

BUILD_DEFS+=		USE_INN

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INN) && ${USE_INN} == YES
DEPENDS=		inn-2.2:../inn
.else
DEPENDS=		nntpclnt-1.6.1:../nntpclnt
.endif

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX=${PREFIX}
CONFIGURE_ARGS=		-S

pre-configure:
	@${CP} ${FILESDIR}/config.sh ${WRKSRC}

post-install:
	@${RM} -f ${PREFIX}/bin/rn ${PREFIX}/man/man1/rn.1 ${PREFIX}/man/man1/rn.1.gz
	@${LN} -s trn ${PREFIX}/bin/rn
	@${LN} -s trn.1 ${PREFIX}/man/man1/rn.1

.include "../../mk/bsd.pkg.mk"
