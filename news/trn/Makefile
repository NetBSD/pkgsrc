# $NetBSD: Makefile,v 1.2 1999/07/26 19:47:37 tron Exp $
#

DISTNAME=		trn-3.6
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.wustl.edu/packages/news/readers/trn/

MAINTAINER=     	packages@netbsd.org

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
	@${LN} -sf trn ${PREFIX}/bin/rn
	@${LN} -sf trn.1 ${PREFIX}/man/man1/rn.1

.include "../../mk/bsd.pkg.mk"
