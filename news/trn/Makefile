# $NetBSD: Makefile,v 1.1.1.1 1999/02/22 16:12:07 tv Exp $
#

DISTNAME=		trn-3.6
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.wustl.edu/packages/news/readers/trn/

MAINTAINER=     	packages@netbsd.org

DEPENDS=		nntpclnt-1.6.1:../../news/nntpclnt

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
