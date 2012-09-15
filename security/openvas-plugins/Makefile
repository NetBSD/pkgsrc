# $NetBSD: Makefile,v 1.8 2012/09/15 10:06:16 obache Exp $
#

DISTNAME=	openvas-plugins-1.0.5
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/539/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Plugins for the Open Vulnerability Assessment System

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bash
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-install=${BINOWN}

REPLACE_BASH+=	openvas-nvt-sync.in

NONFREE=	cisco_vpn_client_detect.nasl js.scob.trojan.nasl \
		nav_installed.nasl patchlink_detection.nasl \
		poptop_negative_read.nasl putty_logon_credential_leak.nasl \
		savce_installed.nasl slad_fetch_results.nasl \
		slad_run.nasl smb_explorer_version.nasl \
		smb_suspicious_files.nasl smb_virii.nasl \
		sonicwall_vpn_client_detect.nasl spybot_detection.nasl \
		spysweeper_corp_installed.nasl ypupdated_remote_exec.nasl

post-extract:
	@${MKDIR} ${WRKSRC}/bin
.	for f in ${NONFREE}
		@${RM} ${WRKSRC}/scripts/${f}
.	endfor

.include "../../security/openvas-libraries/buildlink3.mk"
.include "../../security/openvas-libnasl/buildlink3.mk"
.include "../../security/openvas-server/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
