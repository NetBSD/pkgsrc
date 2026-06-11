# $NetBSD: Makefile,v 1.2 2026/06/11 07:21:25 wiz Exp $

DISTNAME=	socket_wrapper-1.5.0
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	https://ftp.samba.org/pub/cwrap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cwrap.org/socket_wrapper.html
COMMENT=	LD_PRELOAD wrapper to pass all socket I/O through Unix sockets
LICENSE=	modified-bsd

FORTIFY_SUPPORTED=	no	# wraps functions like read

CMAKE_CONFIGURE_ARGS+=	-DUNIT_TESTING:BOOL=TRUE

BUILDLINK_DEPMETHOD.cmocka=	build # for automatic tests only

# Tests are slightly flaky on on NetBSD 9/amd64 (in particular,
# test_sendmmsg_recvmmsg_ipv6 and test_echo_tcp_write_read), possibly
# related to PIPE_BUF being smaller than on Linux, not sure.

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC:Q}/${CMAKE_BUILD_DIR:Q}/src:${WRKSRC:Q}/${CMAKE_BUILD_DIR:Q}/tests
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
