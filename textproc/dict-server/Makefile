# $NetBSD: Makefile,v 1.34 2020/03/30 13:38:58 cheusov Exp $

.include "../../textproc/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/dict-server/}
CATEGORIES=	textproc
COMMENT=	Dictionary Service Protocol server
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake yacc lex m4:run
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-plugin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/dictd

BUILD_DEFS+=		VARBASE
MESSAGE_SUBST+=		VARBASE="${VARBASE}"
MESSAGE_SUBST+=		PATH_TO_M4="${TOOLS_PATH.m4}"
FILES_SUBST+=		PATH_TO_M4="${TOOLS_PATH.m4}"

DICTD_USER?=		dictd
.if ${OPSYS} == "Interix"
DICTD_GROUP?=		nogroup
.else
DICTD_GROUP?=		dictd
.endif

PKG_GROUPS=			${DICTD_GROUP}
PKG_USERS=			${DICTD_USER}:${DICTD_GROUP}
PKG_GECOS.${DICTD_USER}=	Dictionary\ protocol\ server\ user
#PKG_HOME.${DICT_USER}=		/nonexistent
#PKG_SHELL.${DICT_USER}=	${NOLOGIN}

RCD_SCRIPTS=		dictd

# for -L /var/log/dictd/<filename_or_pattern>
OWN_DIRS_PERMS=	${VARBASE}/log/dictd dictd dictd 0750

BUILD_TARGET=	dictd dictzip dictfmt

INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
AUTO_MKDIRS=	yes

CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

EXTRA_DOC_FILES=	COPYING NEWS README INSTALL
EXTRA_EXAMPLES_FILES=	dictd1.conf dictd2.conf \
			dictd3.conf dictd4.conf dictd_complex.conf \
			dictd_mime.conf dictd_plugin_dbi.conf \
			dictd_site.txt dictd_virtual.conf

post-install:
	${INSTALL_DATA} ${.CURDIR}/files/dictd.conf ${DESTDIR}${EGDIR}/
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor
.for i in ${EXTRA_EXAMPLES_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${DESTDIR}${EGDIR}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
