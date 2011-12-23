# $NetBSD: Makefile,v 1.4 2011/12/23 16:44:24 tez Exp $

DISTNAME=	krb5-appl-1.0.1
PKGNAME=	mit-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5-appl/1.0/
DISTFILES=	${DISTNAME}-signed${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar

PATCH_SITES=	http://web.mit.edu/kerberos/advisories/

PATCHFILES=	2011-005-patch.txt

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	http://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system applications

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	mit-krb5<1.8

USE_TOOLS+=		yacc
USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PATCH_DIST_ARGS=	-d ${WRKSRC} -p1

PKG_OPTIONS_VAR=	PKG_OPTIONS.mit-krb5
PKG_SUPPORTED_OPTIONS=	kerberos-prefix-cmds

.include "../../mk/bsd.options.mk"

# Rename some of MIT krb5's applications so they won't conflict with
# other packages.
#
.if !empty(PKG_OPTIONS:Mkerberos-prefix-cmds)
KRB5_PREFIX=		k
MIT_KRB5_TRANSFORM=	s/^ftp/${KRB5_PREFIX}&/;	\
			s/^rcp/${KRB5_PREFIX}&/;	\
			s/^rlogin/${KRB5_PREFIX}&/;	\
			s/^rsh/${KRB5_PREFIX}&/;	\
			s/^telnet/${KRB5_PREFIX}&/
.else
KRB5_PREFIX=		# empty
MIT_KRB5_TRANSFORM=	s/^ftp/k&/
.endif
PLIST_SUBST+=		KRB5_PREFIX=${KRB5_PREFIX:Q}
CONFIGURE_ARGS+=	--program-transform-name=${MIT_KRB5_TRANSFORM:Q}

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

# The MIT krb5 distribution is actually a tar file that contains the
# real .tar.gz distfile and a PGP signature.
#
post-extract:
	@${ECHO} "=> Extracting internal tarball";	\
	extract_file="${WRKDIR}/${DISTNAME}.tar.gz";	\
	cd ${WRKDIR} && ${EXTRACT_CMD}

pre-configure:
	@${ECHO} "=> Generating configure";		\
	cd ${WRKSRC}; autoheader -I ${WRKSRC} -f;	\
	cd ${WRKSRC}; autoconf -I ${WRKSRC} -f;

.include "../../mk/termcap.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/mit-krb5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
