# $NetBSD: Makefile,v 1.2 2001/12/30 17:15:33 taca Exp $
# FreeBSD: ports/devel/ruby-racc-runtime/Makefile,v 1.2 2000/10/08 10:19:28 asami Exp
DISTNAME=	${RACC_DISTFILE}
PKGNAME?=	${RACC_NAME}-runtime-${RACC_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${RACC_SITES}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	${RACC_HOMEPAGE}
COMMENT=	Runtime libraries for Racc.

CONFIGURE_ARGS+=--with=raccrt

pre-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/racc
	${INSTALL_DATA_DIR} ${RUBY_SITEARCHLIBDIR}/racc

.include "../ruby-racc/Makefile.common"
