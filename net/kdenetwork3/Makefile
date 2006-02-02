# $NetBSD: Makefile,v 1.49 2006/02/02 09:31:10 markd Exp $

DISTNAME=	kdenetwork-${_KDE_VERSION}
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

CONFLICTS=	kopete-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=		qca-tls>=1.0:../../security/qca-tls

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		pkg-config
PTHREAD_OPTS+=		require

REPLACE_PERL=		ksirc/dsirc \
			knewsticker/knt-0.1-0.2.pl \
			kopete/kopete/kconf_update/kopete-account-0.10.pl \
			kopete/kopete/kconf_update/kopete-pluginloader.pl

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	/bin/bash
_REPLACE.bash.new=	/bin/sh
_REPLACE_FILES.bash=	krfb/krfb_httpd/krfb_httpd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_header_net_if_ppp_h=yes
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_sys_file_offset_bits=no
.endif

.if !exists(${X11BASE}/lib/libXss.so)
CONFIGURE_ENV+=		ac_cv_lib_Xss_XScreenSaverQueryInfo="no"
.endif

post-configure:
	${TOUCH} ${WRKSRC}/Makefile ${WRKSRC}/config.h
	(cd ${WRKSRC}/kopete/protocols/jabber/libiris/iris/xmpp-core; \
	${MV} Makefile Makefile.save; ${GREP} -v "^#>" Makefile.save > Makefile; \
	${RM} Makefile.save)

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
