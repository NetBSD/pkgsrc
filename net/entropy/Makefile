# $NetBSD: Makefile,v 1.27 2010/02/11 20:53:53 joerg Exp $
#

DISTNAME=		entropy_rsa-${ENTROPY_VERSION}
PKGNAME=		entropy-${ENTROPY_VERSION:S/-/./}
PKGREVISION=		3
WRKSRC=			${WRKDIR}/entropy_rsa-${ENTROPY_VERSION:C/-.*$//}
CATEGORIES=		net www
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Anonymous peer-to-peer networking node (similar to Freenet)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake

ENTROPY_VERSION=	0.9.1-439

CONFIGURE_ARGS+=	--enable-setproctitle --enable-verbose --disable-posix-sem
LIBS+=			-L${BUILDLINK_PREFIX.zlib}/lib -lz -L${BUILDLINK_PREFIX.expat}/lib -lexpat

INSTALLATION_DIRS=	bin share/doc/entropy share/examples/entropy/de \
			share/examples/entropy/node

post-patch:
	${SED} -e '/^# /!s/^#//' <${WRKSRC}/seed.txt-dist >${WRKSRC}/seed.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/entropy_rsa ${DESTDIR}${PREFIX}/bin/entropy
	${INSTALL_PROGRAM} ${WRKSRC}/monoopt ${DESTDIR}${PREFIX}/bin/entropy-monoopt
	${INSTALL_PROGRAM} ${WRKSRC}/storechg ${DESTDIR}${PREFIX}/bin/entropy-storechg
	${INSTALL_DATA} ${WRKSRC}/[ERT]* ${DESTDIR}${PREFIX}/share/doc/entropy/
	${INSTALL_DATA} ${WRKSRC}/entropy_rsa.conf-dist ${DESTDIR}${PREFIX}/share/examples/entropy/entropy.conf
	${INSTALL_DATA} ${WRKSRC}/seed.txt ${DESTDIR}${PREFIX}/share/examples/entropy/
	${INSTALL_DATA} ${WRKSRC}/de/entropy_rsa.lo ${DESTDIR}${PREFIX}/share/examples/entropy/de/entropy.lo
	${INSTALL_DATA} ${WRKSRC}/node/[0-9a-z]* ${DESTDIR}${PREFIX}/share/examples/entropy/node/

.include "../../mk/bsd.prefs.mk"

# tree is most efficient on *ix; can also be "monolithic" or "mysql"
ENTROPY_STORE_TYPE?=	tree

.if ${ENTROPY_STORE_TYPE} == "tree"
CONFIGURE_ARGS+=	--with-tree
.elif ${ENTROPY_STORE_TYPE} == "mysql"
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE:Q}
.include "../../mk/mysql.buildlink3.mk"
.elif ${ENTROPY_STORE_TYPE} != "monolithic"
PKG_FAIL_REASON+=	"unknown ENTROPY_STORE_TYPE: "${ENTROPY_STORE_TYPE:Q}""
.endif

# maximum allowed peer connections (and child processes); default 64
.if defined(ENTROPY_MAX_PEERS)
CONFIGURE_ARGS+=	--enable-max-peers=${ENTROPY_MAX_PEERS:Q}
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
