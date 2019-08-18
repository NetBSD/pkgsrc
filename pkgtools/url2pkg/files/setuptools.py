# $NetBSD: setuptools.py,v 1.1 2019/08/18 11:26:33 rillig Exp $

def url2pkg_print_depends(keyword, depends):
	for dep in depends:
		if '>' not in dep:
			dep = dep + '>=0'
		print('%s\t%s' % (keyword, dep))

def setup(**kwargs):

	if 'install_requires' in kwargs:
		url2pkg_print_depends('DEPENDS', kwargs['install_requires'])

	if 'tests_require' in kwargs:
		url2pkg_print_depends('TEST_DEPENDS', kwargs['tests_require'])
