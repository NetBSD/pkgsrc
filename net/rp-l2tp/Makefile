# $NetBSD: Makefile,v 1.1.1.1 2003/12/18 16:39:18 agc Exp $
#

DISTNAME=	rp-l2tp-0.3
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rp-l2tp/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/rp-l2tp/
COMMENT=	User-space implementation of layer 2 tunnelling protocol

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_GMAKE=	yes

post-patch:
	for f in l2tp.conf.5 l2tpd.8; do				\
		${MV} ${WRKSRC}/man/$$f ${WRKSRC}/man/$$f.in &&		\
		${SED} -e 's|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g'		\
			${WRKSRC}/man/$$f.in > ${WRKSRC}/man/$$f;	\
	done

.include "../../mk/bsd.pkg.mk"
