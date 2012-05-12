# $NetBSD: Makefile,v 1.1.1.1 2012/05/12 07:16:46 wiz Exp $
#

DISTNAME=	man-pages-3.41
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/docs/man-pages/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kernel.org/doc/man-pages/
COMMENT=	The Linux man-pages project for Linux kernel and C library interface
#LICENSE=	many, and not even upstream cares about sorting them out

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX} DESTDIR=${DESTDIR}

# iconv.3, iconv_close.3, iconv_open.3
CONFLICTS+=	libiconv-[0-9]*
# dladdr.3, dlcose.3, dlerror.3, dlopen.3, dlsym.3
CONFLICTS+=	dlcompat-[0-9]*
# getopt_long.3
CONFLICTS+=	libgetopt-[0-9]*
# sem_destroy.3, sem_getvalue.3, sem_init.3, sem_post.3, sem_trywait.3,
# sem_wait.3
CONFLICTS+=	pthread-sem-[0-9]*
# security.2
CONFLICTS+=	cint-[0-9]*
# getaddrinfo.3, gethostbyname.3, getipnodebyname.3, getnameinfo.3,
# getnetent.3, resolver.3, resolver.5, hostname.7
CONFLICTS+=	libbind-[0-9]*
# ftpusers.5
CONFLICTS+=	tnftpd-[0-9]*
# des_crypt.3 (when des option is enabled)
CONFLICTS+=	kth-krb4-[0-9]*
# man.7, mdoc.7
CONFLICTS+=	mdocml-[0-9]*

.include "../../mk/bsd.pkg.mk"
