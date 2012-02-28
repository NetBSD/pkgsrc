# $NetBSD: hacks.mk,v 1.1 2012/02/28 07:20:21 sbd Exp $
.if !defined(HACKS_MK)
HACKS_MK= defined

### [ Tue Feb 28 17:44:28 NZDT 2012 : sbd ]
### The omniORB package install files into ${PYSITELIB}/omniidl_be, 
### but the only files that conflicts are __init__.py with the comment
### "Empty file to convince Python that this is a module." and __init__.pyc.
### So if this package is being built with the same PYTHON_VERSION_DEFAULT as
### omniORB was simply don't install the __int__.py{,c} files.
### 
PKG_HACKS+=	omniidl_be_init
PLIST_VARS+=    omniidl_be_init
.if defined(_PKGSRC_BARRIER)
omniORB_PYTHON_VERSION!=	${PKG_INFO} -Q PYTHON_VERSION_DEFAULT omniORB
.  if "${omniORB_PYTHON_VERSION}" != "${PYTHON_VERSION_DEFAULT}"
PLIST.omniidl_be_init=  yes
INSTALL_ENV+=   INSTALL_OMNIIDL_BE_INIT=yes
.  endif
.endif

.endif  # FOO_HACKS_MK
