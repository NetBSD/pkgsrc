# $NetBSD: Makefile,v 1.7 2023/01/10 17:03:59 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}
GITHUB_PROJECT=		tlswrapper
GITHUB_TAG=		20230101

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/janmojzis/tlswrapper/
COMMENT=		UCSPI/inetd-style TLS encryption wrapper
LICENSE=		cc0-1.0-universal

TEST_TARGET=		test

BUILD_DEFS+=		VARBASE TLSWRAPPER_CHROOT
OWN_DIRS+=		${TLSWRAPPER_CHROOT}
MAKE_ENV+=		EMPTYDIR=${TLSWRAPPER_CHROOT:Q}

LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS=	bin man/man1 share/examples/${PKGBASE}

do-install:
	cd ${WRKSRC};							\
	for i in README.md examples.md; do				\
		${INSTALL_DATA} $${i}					\
			${DESTDIR}${PREFIX}/share/examples/${PKGBASE};	\
	done;								\
	for i in tlswrapper tlswrapper-smtp tlswrapper-tcp; do		\
		${INSTALL_PROGRAM} $${i}				\
			${DESTDIR}${PREFIX}/bin;			\
		${INSTALL_MAN} man/$${i}.1				\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\
	done

.include "../../security/bearssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
