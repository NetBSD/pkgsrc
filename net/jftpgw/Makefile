# $NetBSD: Makefile,v 1.17 2020/04/27 04:47:32 rillig Exp $

DISTNAME=	jftpgw-0.13.5
CATEGORIES=	net
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mcknight.de/jftpgw/
COMMENT=	FTP gateway/proxy

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-logpath=${VARBASE}/log
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-sftp

RCD_SCRIPTS=		jftpgw
EGDIR=			${PREFIX}/share/examples/jftpgw
CONF_FILES=		${EGDIR}/jftpgw.conf ${PKG_SYSCONFDIR}/jftpgw.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	jftpgw.conf.sample
SUBST_SED.config=	-e "s/nobody/root/"

CHECK_PORTABILITY_SKIP+=	support/jftpgw.startscript.non-RH

.include "../../mk/bsd.pkg.mk"
