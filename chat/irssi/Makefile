# $NetBSD: Makefile,v 1.13 2002/06/20 03:29:28 hubertf Exp $

DISTNAME=		irssi-0.8.5
WRKSRC=			${WRKDIR}/irssi-0.8.5
CATEGORIES=		chat
MASTER_SITES=		http://real.irssi.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mutru@iki.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

# list it into IPv6-ready packages
BUILD_DEFS+=		USE_INET6

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-terminfo \
			--enable-ipv6

.include "../../mk/bsd.prefs.mk"

.if defined(IRSSI_USE_PERL) && (${IRSSI_USE_PERL} == "YES")
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Irssi/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/Irc/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/UI/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/TextUI/.packlist
.include "../../lang/perl5/buildlink.mk"
# actually we don't need --with-perl here, irssi is compiled with it by default
# but who knows what may happen in future versions
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-perl-lib=site
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
