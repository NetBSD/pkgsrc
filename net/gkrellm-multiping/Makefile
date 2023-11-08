# $NetBSD: Makefile,v 1.64 2023/11/08 13:20:24 wiz Exp $
#

DISTNAME=	gkrellm-multiping-2.0.8
PKGREVISION=	51
CATEGORIES=	net
#MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/index.html
COMMENT=	Pings several machines and prints out stats

SPECIAL_PERMS+=	${PREFIX}/lib/gkrellm2/plugins/pinger ${SETUID_ROOT_PERMS}

USE_TOOLS+=		pkg-config

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

INSTALLATION_DIRS=	lib/gkrellm2/plugins

post-patch:
	${SED} -e s,@@PREFIX@@,${PREFIX}, ${WRKSRC}/multiping.c > ${WRKSRC}/multiping.c.sed
	${CP} ${WRKSRC}/multiping.c.sed ${WRKSRC}/multiping.c

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
