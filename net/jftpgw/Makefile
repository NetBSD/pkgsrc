# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 01:32:33 xtraeme Exp $

DISTNAME=	    jftpgw-0.13.4
CATEGORIES=	    net
MASTER_SITES=	    http://www.mcknight.de/jftpgw/

MAINTAINER=	    david@netbsd-fr.org
HOMEPAGE=	    http://www.mcknight.de/jftpgw/
COMMENT=	    FTP gateway/proxy

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--with-logpath=/var/log
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-sftp

RCD_SCRIPTS=		jftpgw
EGDIR=			${PREFIX}/share/examples/jftpgw
CONF_FILES=		${EGDIR}/jftpgw.conf ${PKG_SYSCONFDIR}/jftpgw.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	${WRKSRC}/jftpgw.conf.sample
SUBST_SED.config=	-e "s/nobody/root/"

.include "../../mk/bsd.pkg.mk"
