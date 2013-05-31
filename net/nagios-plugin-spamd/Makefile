# $NetBSD: Makefile,v 1.6 2013/05/31 12:41:35 wiz Exp $
#

DISTNAME=	check_spamd-1.4.pl
PKGNAME=	nagios-plugin-spamd-${DISTNAME:S/check_spamd-//:S/.pl//}
PKGREVISION=	2
CATEGORIES=	net mail
MASTER_SITES=	# ftp://jhweiss.de/pub/users/weiss/nagios/plugins/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jhweiss.de/software/nagios.html
COMMENT=	Nagios plugin for monitoring the SpamAssassin daemon

DEPENDS+=		nagios-plugins-[0-9]*:../../net/nagios-plugins

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

USE_TOOLS+=		perl:run

REPLACE_PERL+=		${DISTNAME}

PLUGIN_DIR=		${PREFIX}/libexec/nagios

SUBST_CLASSES+=		check_spamd
SUBST_STAGE.check_spamd=post-configure
SUBST_FILES.check_spamd=${DISTNAME}
SUBST_SED.check_spamd=	-e 's,/usr/local/nagios/libexec,${PLUGIN_DIR},'

INSTALLATION_DIRS+=	${PLUGIN_DIR}

do-extract:
	cp "${DISTDIR}/${DISTNAME}" "${WRKDIR}"

do-install:
	${INSTALL_SCRIPT} "${WRKDIR}/${DISTNAME}" \
		"${DESTDIR}${PLUGIN_DIR}/check_spamd"

.include "../../mk/bsd.pkg.mk"
