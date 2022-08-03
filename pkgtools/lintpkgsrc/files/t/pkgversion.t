# $NetBSD: pkgversion.t,v 1.7 2022/08/03 20:50:43 rillig Exp $

use strict;
use warnings;
use Test;

BEGIN { plan tests => 6, onfail => sub { die } }

require('../lintpkgsrc.pl');

ok(pkgversioncmp('3.4', '<', '3.4'), '');
ok(pkgversioncmp('3.4', '<=', '3.4'), 1);
ok(pkgversioncmp('3.4', '>=', '3.4.0.0.0'), 1);
ok(pkgversioncmp('3.4nb13', '>=', '3.4'), 1);
ok(pkgversioncmp('3.4nb13', '<', '3.4'), '');
ok(pkgversioncmp('3.4nb13', '>', '3.4nb5'), 1);
ok(pkgversioncmp('1.1ab', '>', '1.1aa'), 1);
ok(pkgversioncmp('1.1ab', '<=', '1.1.1.2'), 1);
ok(pkgversioncmp('1.1ab', '>=', '1.1.1.2'), 1);
