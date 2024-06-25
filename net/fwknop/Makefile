# $NetBSD: Makefile,v 1.6 2024/06/25 07:08:23 adam Exp $

DISTNAME=	fwknop-2.6.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrash/fwknop/
COMMENT=	Port knocking via Single Packet Authorization (SPA)
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=	aclocal autoconf automake autoheader makeinfo

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

RCD_SCRIPTS=		fwknopd
EGDIR=			${PREFIX}/share/examples/fwknop
CONF_FILES_PERMS+=	${EGDIR}/access.conf \
			${PKG_SYSCONFDIR}/fwknop/access.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/fwknopd.conf \
			${PKG_SYSCONFDIR}/fwknop/fwknopd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
INSTALLATION_DIRS+=	${EGDIR}

INFO_FILES=	yes

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/fwknop/access.conf ${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/fwknop/fwknopd.conf ${DESTDIR}${EGDIR}/

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
