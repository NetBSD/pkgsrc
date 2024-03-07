# $NetBSD: Makefile,v 1.1 2024/03/07 11:48:35 hauke Exp $

NAME=		softether
VERSION=	5.02.5181
PKGNAME=	${NAME}-${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_RELEASE}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=SoftEtherVPN/}
GITHUB_PROJECT=	SoftEtherVPN
GITHUB_RELEASE=	${VERSION}
EXTRACT_SUFX=	.tar.xz

DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.softether.org/
COMMENT=	Powerful and easy-to-use multi-protocol VPN software
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config cmake

USE_CMAKE=	yes

USE_LANGUAGES=	c

DOC_FILES=	DISCLAIMER.md README.md SECURITY.md LICENSE AUTHORS.TXT

RCD_SCRIPTS=	softether_bridge softether_client softether_server

FILES_SUBST+=	SE_PIDDIR=${SE_PIDDIR}

BUILD_DEFS+=	VARBASE

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DSE_DBDIR="${SE_DBDIR}" \
		-DSE_LOGDIR="${SE_LOGDIR}" \
		-DSE_PIDDIR="${SE_PIDDIR}"

SE_DBDIR?=	${VARBASE}/db/${NAME}
SE_LOGDIR?=	${VARBASE}/log/${NAME}
SE_PIDDIR?=	${VARBASE}/run/${NAME}

INSTALLATION_DIRS+=	bin share/doc/${NAME}

OWN_DIRS+=	${SE_DBDIR}
OWN_DIRS+=	${SE_LOGDIR}

post-install:
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
		${DESTDIR}${PREFIX}/share/doc/${NAME}/${x}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/cpu_features/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
