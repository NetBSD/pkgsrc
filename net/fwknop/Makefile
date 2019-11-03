# $NetBSD: Makefile,v 1.2 2019/11/03 11:45:35 rillig Exp $

DISTNAME=	fwknop-2.6.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrash/fwknop/
COMMENT=	Port knocking via Single Packet Authorization (SPA)
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=	aclocal autoconf automake autoheader makeinfo

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}

EGDIR=			${PREFIX}/share/examples/fwknop
CONF_FILES+=		${EGDIR}/access.conf \
			${PKG_SYSCONFDIR}/fwknop/access.conf
CONF_FILES+=		${EGDIR}/fwknopd.conf \
			${PKG_SYSCONFDIR}/fwknop/fwknopd.conf
INSTALLATION_DIRS+=	${EGDIR}

INFO_FILES=	yes

WRKSRC=		${WRKDIR}/fwknop-2.6.9

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/fwknop/access.conf ${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/fwknop/fwknopd.conf ${DESTDIR}${EGDIR}/

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
