# $NetBSD: Makefile,v 1.5 2004/11/12 06:39:20 jlam Exp $
#

DISTNAME=	gkrellm-multiping-2.0.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/index.html
COMMENT=	Pings several machines and prints out stats

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
SPECIAL_PERMS+=	${PREFIX}/lib/gkrellm2/plugins/pinger ${SETUID_ROOT_PERMS}
PTHREAD_OPTS=	require

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, ${WRKSRC}/multiping.c > ${WRKSRC}/multiping.c.sed
	${CP} ${WRKSRC}/multiping.c.sed ${WRKSRC}/multiping.c

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
