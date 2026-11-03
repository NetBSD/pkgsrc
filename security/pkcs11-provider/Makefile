# $NetBSD: Makefile,v 1.4 2026/11/03 15:04:06 wiz Exp $

DISTNAME=	pkcs11-provider-1.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=openssl-projects/pkcs11-provider/releases/download/v1.3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openssl-projects/pkcs11-provider
COMMENT=	OpenSSL provider for PKCS\#11 modules
LICENSE=	apache-2.0

USE_TOOLS+=	bash:test pkg-config

MESON_ARGS+=	${${USE_BUILTIN.openssl} == "yes":?-Dmodules_dir=${PREFIX:Q}/lib/ossl-modules:}

REPLACE_BASH+=	scripts/clean-dist.sh
REPLACE_BASH+=	scripts/coverage/run_tests.py
REPLACE_BASH+=	scripts/coverage_report.sh
REPLACE_BASH+=	tests/helpers.sh
REPLACE_BASH+=	tests/integration/bind.sh
REPLACE_BASH+=	tests/integration/httpd.sh
REPLACE_BASH+=	tests/integration/libssh.sh
REPLACE_BASH+=	tests/kryoptic-init.sh
REPLACE_BASH+=	tests/kryoptic.multislot-init.sh
REPLACE_BASH+=	tests/kryoptic.nss-init.sh
REPLACE_BASH+=	tests/setup.sh
REPLACE_BASH+=	tests/softhsm-init.sh
REPLACE_BASH+=	tests/softokn-init.sh
REPLACE_BASH+=	tests/taead
REPLACE_BASH+=	tests/tbasic
REPLACE_BASH+=	tests/tcerts
REPLACE_BASH+=	tests/tcms
REPLACE_BASH+=	tests/tdefaultslot
REPLACE_BASH+=	tests/tdemoca
REPLACE_BASH+=	tests/tdigest
REPLACE_BASH+=	tests/tecc
REPLACE_BASH+=	tests/tecdh
REPLACE_BASH+=	tests/tecxc
REPLACE_BASH+=	tests/tedwards
REPLACE_BASH+=	tests/tforking
REPLACE_BASH+=	tests/thkdf
REPLACE_BASH+=	tests/timported
REPLACE_BASH+=	tests/tmldsa
REPLACE_BASH+=	tests/tmlkem
REPLACE_BASH+=	tests/toaepsha2
REPLACE_BASH+=	tests/top_state
REPLACE_BASH+=	tests/tpem_encoder
REPLACE_BASH+=	tests/tpinlock
REPLACE_BASH+=	tests/tpkey_provider
REPLACE_BASH+=	tests/tpubkey
REPLACE_BASH+=	tests/trand
REPLACE_BASH+=	tests/trsa
REPLACE_BASH+=	tests/trsapss
REPLACE_BASH+=	tests/trsapssam
REPLACE_BASH+=	tests/tskey
REPLACE_BASH+=	tests/tslhdsa
REPLACE_BASH+=	tests/ttls
REPLACE_BASH+=	tests/ttlsfuzzer
REPLACE_BASH+=	tests/turi

# generated file, doesn't exist when REPLACE_BASH happens
SUBST_CLASSES+=		bash
SUBST_SED.bash=		-e "s,/bin/bash.*,${BASH},"
SUBST_FILES.bash+=	tests/test-wrapper
SUBST_STAGE.bash=	post-configure
SUBST_MESSAGE.bash=	Fixing path to bash.


.include "../../devel/meson/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
