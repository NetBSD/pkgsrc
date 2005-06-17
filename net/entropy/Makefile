# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=		entropy-${ENTROPY_VERSION}
PKGNAME=		entropy-${ENTROPY_VERSION:S/-/./}
PKGREVISION=		2
WRKSRC=			${WRKDIR}/entropy-${ENTROPY_VERSION:C/-.*$//}
CATEGORIES=		net www
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Anonymous peer-to-peer networking node (similar to Freenet)

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ENTROPY_VERSION=	0.8.2-418

CONFIGURE_ARGS+=	--enable-setproctitle --enable-verbose --disable-posix-sem

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e '/^# /!s/^#//' <${WRKSRC}/seed.txt-dist >${WRKSRC}/seed.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/entropy ${PREFIX}/bin/entropy
	${INSTALL_PROGRAM} ${WRKSRC}/monoopt ${PREFIX}/bin/entropy-monoopt
	${INSTALL_PROGRAM} ${WRKSRC}/storechg ${PREFIX}/bin/entropy-storechg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy/node
	${INSTALL_DATA} ${WRKSRC}/entropy.conf-dist ${PREFIX}/share/examples/entropy/entropy.conf
	${INSTALL_DATA} ${WRKSRC}/seed.txt ${PREFIX}/share/examples/entropy/
	${INSTALL_DATA} ${WRKSRC}/node/[0-9a-z]* ${PREFIX}/share/examples/entropy/node/

.include "../../mk/bsd.prefs.mk"

# tree is most efficient on *ix; can also be "monolithic" or "mysql"
ENTROPY_STORE_TYPE?=	tree

.if ${ENTROPY_STORE_TYPE} == "tree"
CONFIGURE_ARGS+=	--with-tree
.elif ${ENTROPY_STORE_TYPE} == "mysql"
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.include "../../mk/mysql.buildlink3.mk"
.elif ${ENTROPY_STORE_TYPE} != "monolithic"
.error unknown ENTROPY_STORE_TYPE: ${ENTROPY_STORE_TYPE}
.endif

# maximum allowed peer connections (and child processes); default 64
.ifdef ENTROPY_MAX_PEERS
CONFIGURE_ARGS+=	--enable-max-peers=${ENTROPY_MAX_PEERS}
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
