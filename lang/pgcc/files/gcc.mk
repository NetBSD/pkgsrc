# make configuration file for @@PKGNAME@@

CC=	@@PREFIX@@/@@PKGNAME@@/bin/cc
CPP=	@@PREFIX@@/@@PKGNAME@@/bin/cpp
CXX=	@@PREFIX@@/@@PKGNAME@@/bin/c++

.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
