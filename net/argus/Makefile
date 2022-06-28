# $NetBSD: Makefile,v 1.31 2022/06/28 11:34:57 wiz Exp $

DISTNAME=	argus-3.7
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	argus@tcp4me.com
HOMEPAGE=	http://argus.tcp4me.com/
COMMENT=	System and Network Monitoring Application
LICENSE=	artistic

BUILD_DEFS+=	VARBASE

DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-GD>=2.11:../../graphics/p5-GD
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--bin_dir ${PREFIX}/bin
CONFIGURE_ARGS+=	--sbin_dir ${PREFIX}/sbin
CONFIGURE_ARGS+=	--lib_dir ${PREFIX}/lib/argus
CONFIGURE_ARGS+=	--cgi_dir ${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--data_dir ${VARBASE}/argus
CONFIGURE_ARGS+=	--www_dir ${VARBASE}/argus/www/htdocs
CONFIGURE_ENV+=		PERL=${TOOLS_PERL5:Q}

RCD_SCRIPTS=		argusd

INSTALL_MAKE_FLAGS+=	INSTALL_BIN=${DESTDIR}${PREFIX}/bin \
			INSTALL_SBIN=${DESTDIR}${PREFIX}/sbin \
			INSTALL_CGI=${DESTDIR}${PREFIX}/libexec/cgi-bin \
			INSTALL_LIB=${DESTDIR}${PREFIX}/lib/argus \
			INSTALL_DATA=${DESTDIR}${PREFIX}/share/examples/argus

OWN_DIRS_PERMS=		${VARBASE}/argus ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0777
OWN_DIRS_PERMS+=	${VARBASE}/argus/perl ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0777
OWN_DIRS_PERMS+=	${VARBASE}/argus/gcache ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0777
OWN_DIRS_PERMS+=	${VARBASE}/argus/gdata ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0777
OWN_DIRS=		${VARBASE}/argus/stats
OWN_DIRS+=		${VARBASE}/argus/notify
OWN_DIRS+=		${VARBASE}/argus/locale
OWN_DIRS+=		${VARBASE}/argus/html
CONF_FILES=		${PREFIX}/share/examples/argus/config.example ${VARBASE}/argus/config
CONF_FILES+=		${PREFIX}/share/examples/argus/users.example ${VARBASE}/argus/users
CONF_FILES+=		${PREFIX}/share/examples/argus/log ${VARBASE}/argus/log
CONF_FILES+=		${PREFIX}/share/examples/argus/notno ${VARBASE}/argus/notno
.for f in de_DE el_gr fr_fr lt_LT nl_NL piglatin ru_RU sp_ar template
CONF_FILES+=		${PREFIX}/share/examples/argus/locale/${f} ${VARBASE}/argus/locale/${f}
.endfor

post-install:
	(cd ${DESTDIR}${PREFIX}/share/examples/argus; chmod 755 . perl gcache gdata)

.include "../../mk/bsd.pkg.mk"
