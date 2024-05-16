# $NetBSD: Makefile,v 1.7 2024/05/16 06:15:36 wiz Exp $

GITHUB_PROJECT=	swtpm
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	swtpm-0.7.0
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=stefanberger/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefanberger/swtpm/
COMMENT=	Software TPM (Trusted Platform Module) emulator
LICENSE=	modified-bsd

TOOL_DEPENDS+=		tcl-expect-[0-9]*:../../lang/tcl-expect
TOOL_DEPENDS+=		socat-[0-9]*:../../net/socat

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_MESSAGE.varbase=	Use VARBASE
SUBST_FILES.varbase+=	configure.ac
SUBST_VARS.varbase=	VARBASE

BUILD_DEFS+=		VARBASE

USE_LANGUAGES+=		c

# Avoid `error: 'saved_stack.30' may be used uninitialized in this function [-Werror=maybe-uninitialized]` or similar errors
BUILDLINK_TRANSFORM+=	rm:-Werror

USE_LIBTOOL=		yes
USE_TOOLS=		automake bash gawk gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS+=	--without-cuse
CONFIGURE_ARGS+=	--with-tss-user=${REAL_ROOT_USER}
CONFIGURE_ARGS+=	--with-tss-group=${REAL_ROOT_GROUP}
# Avoid `error: stack protector not protecting local variables: variable length buffer [-Werror=stack-protector]` errors
CONFIGURE_ARGS+=	--disable-hardening

REPLACE_BASH+=		samples/*

EGDIR=		${PREFIX}/share/examples/swtpm
CONF_FILES+=	${EGDIR}/swtpm-localca.conf \
		${PKG_SYSCONFDIR}/swtpm-localca.conf
CONF_FILES+=	${EGDIR}/swtpm-localca.options \
		${PKG_SYSCONFDIR}/swtpm-localca.options
CONF_FILES+=	${EGDIR}/swtpm_setup.conf \
		${PKG_SYSCONFDIR}/swtpm_setup.conf

OWN_DIRS_PERMS+=	${VARBASE}/lib/swtpm-localca \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/libtpms/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
