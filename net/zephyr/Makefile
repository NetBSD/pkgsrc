# $NetBSD: Makefile,v 1.27 2003/07/30 10:53:02 jmmv Exp $
#

DISTNAME=	zephyr-2.0.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html
COMMENT=	Zephyr Messaging Service

CONFLICTS+=	kth-krb4-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+="--with-krb4"
CPPFLAGS+=	-I/usr/include/kerberosIV
.else
CONFIGURE_ARGS+="--without-krb4"
.endif

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

RCD_SCRIPTS=	zhm

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"
PKG_SYSCONFSUBDIR=	zephyr
OWN_DIRS=		${PKG_SYSCONFDIR}/acl
EGDIR=			${PREFIX}/share/examples/zephyr
CONF_FILES=		# Contents set in HEADER file

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/acl
	${INSTALL_DATA_DIR} ${ZEPHYR_DOCDIR}
.for f in ${ZEPHYR_DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${ZEPHYR_DOCDIR}
.endfor
.undef f

.include "../../mk/bsd.pkg.mk"
