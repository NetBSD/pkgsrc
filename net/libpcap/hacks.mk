# $NetBSD: hacks.mk,v 1.1 2007/10/14 22:49:43 tron Exp $

# Some versions of NetBSD 3.x and some NetBSD 4.0 release candidates don't
# include "/usr/include/net/if_pflog.h" which breaks the build. Work around
# this by pretending we didn't find "/usr/include/net/pfvar.h".

.if exists(/usr/include/net/pfvar.h) && !exists(/usr/include/net/if_pflog.h)
SUBST_CLASSES+=		pflog
SUBST_MESSAGE.pflog=	Disabling pflog(4) support because "net/if_pflog.h" is missing.
SUBST_STAGE.pflog=	post-configure
SUBST_FILES.pflog=	config.h
SUBST_SED.pflog=	-e 's/^\#define.*HAVE_NET_PFVAR_H.*//'

PKG_HACKS+=		pflog
.endif
