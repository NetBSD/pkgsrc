# $NetBSD: Makefile,v 1.21 2022/06/28 11:35:03 wiz Exp $

DISTNAME=	check_spamd-1.6.0
PKGNAME=	nagios-plugin-${DISTNAME:S/check_//1}
PKGREVISION=	9
CATEGORIES=	net mail
MASTER_SITES=	# http://exchange.nagios.org/components/com_mtree/
EXTRACT_SUFX=	.pl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://exchange.nagios.org/directory/Plugins/Email-and-Groupware/SpamAssasin/check_spamd
COMMENT=	Nagios plugin for monitoring the SpamAssassin daemon
LICENSE=	gnu-gpl-v3

DEPENDS+=		nagios-plugins-[0-9]*:../../net/nagios-plugins
#DEPENDS+=		p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=		p5-Switch-[0-9]*:../../lang/p5-Switch
DEPENDS+=		spamassassin-[0-9]*:../../mail/spamassassin

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

USE_TOOLS+=		perl:run

# Fix interpreter line in check_spamd script.
REPLACE_PERL+=		${DISTFILES}

PLUGIN_DIR=		${PREFIX}/libexec/nagios

# Fix embedded path to spamc within check_spamd script.
SUBST_CLASSES+=			check_spamd
SUBST_STAGE.check_spamd=	post-configure
SUBST_FILES.check_spamd=	${DISTFILES}
SUBST_MESSAGE.check_spamd=	Fixing path to spamc.
SUBST_SED.check_spamd=		-e 's|/usr/local/perl/bin/|${PREFIX}/bin/|1'

INSTALLATION_DIRS+=	${PLUGIN_DIR}

do-install:
	${INSTALL_SCRIPT} "${WRKDIR}/${DISTFILES}" \
		"${DESTDIR}${PLUGIN_DIR}/check_spamd"

.include "../../mk/bsd.pkg.mk"
