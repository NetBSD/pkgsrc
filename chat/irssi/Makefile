# $NetBSD: Makefile,v 1.19.2.1 2003/12/12 11:53:48 agc Exp $

DISTNAME=		${IRSSI_DISTNAME}
CATEGORIES=		chat
MASTER_SITES=		http://real.irssi.org/files/
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		mutru@iki.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

.include "${.CURDIR}/Makefile.common"

# list it into IPv6-ready packages
BUILD_DEFS+=		USE_INET6 IRSSI_USE_SSL

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--with-terminfo \
			--without-ncurses \
			--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

.include "../../mk/bsd.prefs.mk"

.if defined(IRSSI_USE_PERL) && (${IRSSI_USE_PERL} == "YES")
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Irssi/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/Irc/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/UI/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/TextUI/.packlist
.include "../../lang/perl5/buildlink2.mk"
# actually we don't need --with-perl here, irssi is compiled with it by default
# but who knows what may happen in future versions
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-perl-lib=site
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

# IPv6 support
.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# SSL support
.if defined(IRSSI_USE_SSL) && !empty(IRSSI_USE_SSL:M[Yy][Ee][Ss])
.  include "../../security/openssl/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif


post-install:
	${INSTALL_DATA} ${WRKSRC}/config.h ${IRSSI_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${IRSSI_CONFIG}

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
