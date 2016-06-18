# $NetBSD: waf.mk,v 1.4 2016/06/18 10:30:14 leot Exp $

WAF_ENV+=	CC=${CC:Q}
WAF_ENV+=	CFLAGS=${CFLAGS:Q}
WAF_ENV+=	CXX=${CXX:Q}
WAF_ENV+=	CXXFLAGS=${CXXFLAGS:Q}
WAF_ENV+=	DESTDIR=${DESTDIR}
WAF_ENV+=	LINKFLAGS=${LDFLAGS:Q}
WAF_ENV+=	PATH=${PATH:Q}
WAF_ENV+=	PREFIX=${PREFIX}
.if defined(MAKE_JOBS)
WAF_ENV+=	JOBS=${MAKE_JOBS:Q}
.endif

# Kludge to support rst2man on Mac OS X, PR pkg/49921
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
WAF_ENV+=	LC_ALL="en_US.UTF-8"
.endif

WAF_HAS_MANDIR?=	yes
.if !empty(WAF_HAS_MANDIR:M[yY][eE][sS])
WAF_ARGS+=		--mandir=${PREFIX}/${PKGMANDIR}
.endif

post-extract:
	cp ${PREFIX}/bin/waf ${WRKSRC}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS} ${WAF_CONFIGURE_ARGS} configure

do-build:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS} install
