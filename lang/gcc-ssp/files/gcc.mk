# make configuration file for @@PKGBASENAME@@

CC=	@@PREFIX@@/@@PKGBASENAME@@/bin/cc
CPP=	@@PREFIX@@/@@PKGBASENAME@@/bin/cpp
CXX=	@@PREFIX@@/@@PKGBASENAME@@/bin/c++

.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
